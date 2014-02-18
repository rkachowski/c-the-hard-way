set -e

if [ ! -f devpkg ];then
    echo "devpkg executable not found! compile it first"
    exit 1
fi

#test init
./devpkg -S

echo "-S (init) works!"

./devpkg -I http://archive.apache.org/dist/apr/apr-1.4.6.tar.gz

echo "-I (install) works!"

./devpkg -L

echo "-L (list) works!"

./devpkg -F https://github.com/rkachowski/fag-blaster.git

echo "-F (fetch) works!"

./devpkg -I http://archive.apache.org/dist/apr/apr-1.4.6.tar.gz

echo "-B (build) works!"


echo "If you can see this, everything is peachy."
