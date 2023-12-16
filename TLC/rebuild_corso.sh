docker build -t ns-3-corso -f Dockerfile.Corso . --no-cache

docker run -d -it --name ns-3-corso ns-3-corso
docker exec -it ns-3-corso bash