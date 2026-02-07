from python:latest as build

workdir /app

run pip install \
        mkdocs \
        mkdocs-material \
        mkdocstrings-python \
        mkdocstrings-shell \
        pymdown-extensions

copy . /app

run mkdocs build -d site

from caddy:2.11-alpine

workdir /site

copy --from=build /app/site .

entrypoint ["caddy", "file-server"]
