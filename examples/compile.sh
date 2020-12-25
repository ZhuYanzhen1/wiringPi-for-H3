#!/bin/bash
echo "Start Conpile $1 To $2"
gcc $1 -o $2 -lwiringPi -lwiringPiDev -lpthread -lm -lcrypt -lrt $S3
echo "Compile Finished!!"

