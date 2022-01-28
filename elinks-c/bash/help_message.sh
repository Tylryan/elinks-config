#!/usr/bin/bash

PROGRAM_NAME=$1

echo -e "USAGE
    $PROGRAM_NAME [options] [website-url]
    $PROGRAM_NAME [options] [your-question]
DESCRIPTION
    Searches the web from your terminal using Elinks
OPTIONS
    No args is equivalent to running \"elinks\"
    -h      --help      Shows this message and exits.
    -o      --otter     Runs otter-browser instead of elinks.
EXAMPLES
    $PROGRAM_NAME google.com?
    $PROGRAM_NAME how big is the moon?"
