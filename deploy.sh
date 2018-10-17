scp cbackend.sh cbackend@roadcloud:~/
scp runp.sh cbackend@roadcloud:~/
scp kill.sh cbackend@roadcloud:~/
scp environment cbackend@roadcloud:~/.ssh
ssh cbackend@roadcloud "./kill.sh"
scp -r cfg cbackend@roadcloud:~/
ssh cbackend@roadcloud "if [ ! -d log ]; then (mkdir log); fi"

tar cvfz netd.tgz bin/netd
tar cvfz feed.tgz bin/feed
scp netd.tgz feed.tgz cbackend@roadcloud:~/
rm -f netd.tgz feed.tgz
ssh cbackend@roadcloud "rm -f bin/netd bin/feed; tar xvfz netd.tgz; tar xvfz feed.tgz; ./runp.sh 1>/dev/null"
