#!/usr/bin/env bash
# Builds and runs the tests three ways: plain, under ASan+UBSan, under Valgrind.
# Exits non-zero if any run fails. (Stage 1 build item: extend this as you add exercises.)
set -euo pipefail
cd "$(dirname "$0")"

status=0
for target in test asan valgrind; do
    echo "== make $target =="
    if ! make -s "$target"; then
        echo "!! $target failed"
        status=1
    fi
done
make -s clean
exit "$status"
