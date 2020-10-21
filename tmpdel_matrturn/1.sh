(git clone https://github.com/matrix-org/synapse.git&&cp tmpdel_matrturn/turnserver.conf synapse/docker/conf/&&cp tmpdel_matrturn/Dockerfile synapse/docker/&&cp tmpdel_matrturn/start.py synapse/docker/)
(cd synapse&&docker build -t matrix/synap -f docker/Dockerfile .)
(docker run -it --rm --mount type=volume,src=synapse-data,dst=/data -e SYNAPSE_SERVER_NAME=my.matrix.host -e SYNAPSE_REPORT_STATS=yes matrix/synap:latest generate)
