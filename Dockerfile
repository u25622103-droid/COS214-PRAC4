FROM gcc:latest

WORKDIR /app

# Install valgrind
RUN apt-get update && apt-get install -y \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# Copy all source files
COPY *.h *.cpp Makefile ./

# Build the project
RUN make clean && make

# Run the application
CMD ["./taskforge"]