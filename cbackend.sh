#!/bin/bash
#
RETVAL=0;

do_start() {
echo "Starting cbackend"
su - cbackend -c "./runp.sh"
}

do_stop() {
echo "Stopping cbackend"
su - cbackend -c "./kill.sh"
}

do_restart() {
do_stop
do_start
}

case "$1" in
start)
  do_start
;;
stop)
  do_stop
;;
restart)
  do_restart
;;
*)
echo $"Usage: $0 {start|stop|restart}"
exit 1
esac

exit $RETVAL
