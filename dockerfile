FROM fifczak/ubuntu_develop:latest
COPY . Test
RUN cd Test/src && mkdir out
WORKDIR /Test/src/out
RUN cmake -GNinja ..
RUN ninja
CMD ["./GNIOT"]