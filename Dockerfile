FROM alpine:latest

ENV NAME GuessThePokemon

LABEL maintainer=doer08736
LABEL title=$NAME 
LABEL version=0.0

RUN apk add gcc musl-dev sqlite-dev --no-cache

COPY . /$NAME

WORKDIR /$NAME/code

CMD cc main.c -lsqlite3 && ./a.out	
