# doubler PHP extension

A demo PHP extension implmented with Rust (see [here](https://github.com/cwchentw/libdoubler-rust-demo)) and glued with [PHP-CPP](http://www.php-cpp.com/).

## Demo

Rust doesn't generate header and other related files automatically; therefore, you have to implement it by yourself.  In this demo case, put `doubler.h` to `/usr/local/include` and `libdoubler.so`, generated from our Rust project, to `/usr/local/lib`.  Then, add the path `/usr/local/lib` to `/etc/ld.so.conf.d/doubler.conf`.  Finally, feed the following commands:

```
$ make
$ php -dextension=`pwd`/doubler.so main.php
```
