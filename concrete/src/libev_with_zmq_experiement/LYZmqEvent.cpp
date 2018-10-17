#include "../../concrete/src/LYZmqEvent.h"

#include <stdexcept>
#include <iostream>


LYZmqEvent::LYZmqEvent(zmq::context_t& context,
		zmq::socket_t& soc) : socket(soc) {
    // Get the file descriptor for the socket
    size_t fd_len = sizeof(socket_fd);
    socket.getsockopt(ZMQ_FD, &socket_fd, &fd_len);

    // Set up all of our watchers

    // Have our IO watcher check for READ on the ZeroMQ socket
    watcher_io.set(socket_fd, ev::READ);

    // This watcher has a no-op callback
    watcher_io.set<LYZmqEvent, &LYZmqEvent::noop>(this);

    // Set up our prepare watcher to call the before() function
    watcher_prepare.set<LYZmqEvent, &LYZmqEvent::before>(this);

    // Set up the check watcher to call the after() function
    watcher_check.set<LYZmqEvent, &LYZmqEvent::after>(this);

    // Set up our idle watcher, once again a no-op
    watcher_idle.set<LYZmqEvent, &LYZmqEvent::noop>(this);

    // Tell libev to start notifying us!
    start_notify();
}

LYZmqEvent::~LYZmqEvent() {}

void LYZmqEvent::before(ev::prepare&, int revents)
{
	std::cout << "zmqev::before" << std::endl;
    if (EV_ERROR & revents) {
        throw std::runtime_error("libev error");
    }

    // Get any events that may be waiting
    uint32_t zevents = 0;
    size_t zevents_len = sizeof(zevents);

    // Lucky for us, getting the events available doesn't invalidate the
    // events, so that calling this in `before()` and in `after()` will
    // give us the same results.
    socket.getsockopt(ZMQ_EVENTS, &zevents, &zevents_len);

    // Check what events exists, and check it against what event we want. We
    // "abuse" our watcher_io.events for this information.
    if ((zevents & ZMQ_POLLOUT) && (watcher_io.events & ev::WRITE)) {
        watcher_idle.start();
        return;
    }

    if ((zevents & ZMQ_POLLIN) && (watcher_io.events & ev::READ)) {
        watcher_idle.start();
        return;
    }

    // No events ready to be processed, we'll just go watch some io
    watcher_io.start();
}

void LYZmqEvent::after(ev::check&, int revents)
{
    if (EV_ERROR & revents) {
        throw std::runtime_error("libev error");
    }

    // Stop both the idle and the io watcher, no point in calling the no-op callback
    // One of them will be reactived by before() on the next loop
    watcher_idle.stop();
    watcher_io.stop();

    // Get the events
    uint32_t zevents = 0;
    size_t zevents_len = sizeof(zevents);
    socket.getsockopt(ZMQ_EVENTS, &zevents, &zevents_len);

    // Check the events and call the users read/write function
    if ((zevents & ZMQ_POLLIN) && (watcher_io.events & ev::READ)) {
        this->read();
    }

    if ((zevents & ZMQ_POLLOUT) && (watcher_io.events & ev::WRITE)) {
        this->write();
    }
}

void LYZmqEvent::start_notify()
{
	std::cout << "start_notify..." << std::endl;
    watcher_check.start();
    watcher_prepare.start();
}

void LYZmqEvent::stop_notify()
{
    watcher_check.stop();
    watcher_prepare.stop();
}
