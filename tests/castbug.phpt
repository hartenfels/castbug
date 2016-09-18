--TEST--
castbug
--DESCRIPTION--
Casts happen in the wrong order.
--FILE--
<?php
$cb = new CastBug();

/* these work as expected */
var_dump((int) $cb);
var_dump((float) $cb);

/* these use integer conversion instead of double conversion */
var_dump($cb + 1.5);
var_dump($cb * 2.0);
var_dump($cb / 10.0);
?>
--EXPECT--
int(123)
float(31.41)
float(32.91)
float(62.82)
float(3.141)
