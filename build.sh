#!/bin/sh
set -e

DEVICE=${DEVICE:-ARM64_A53}
BUILD=${BUILD:-test}

cd /workspace/frontend

make DEVICE="$DEVICE" BUILD="$BUILD"
