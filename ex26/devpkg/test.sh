set -e

if [ ! -f devpkg ];then
    echo "devpkg executable not found! compile it first"
    exit 1
fi

#test init
./devpkg -S
