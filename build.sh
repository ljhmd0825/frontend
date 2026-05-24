#!/bin/sh
set -e

DEVICE=${DEVICE:-ARM64_A53}
BUILD=${BUILD:-test}

cd /workspace/frontend

git checkout e57abbb2
make DEVICE="$DEVICE" BUILD="$BUILD"
