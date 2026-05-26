#!/bin/sh
set -e

DEVICE=${DEVICE:-ARM64_A53}
BUILD=${BUILD:-release}

cd /workspace/frontend

make DEVICE="$DEVICE" BUILD="$BUILD"
