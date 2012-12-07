<?php
    function isPandigital( $a, $b, $c ){
        if( strlen( $a . $b . $c ) != 9 ){
            return false;
        }
        $all = array();
        foreach( str_split( $a . $b . $c ) as $i ){
            $all[ $i ] = true;
        }
        for( $i = 1; $i < 10; ++$i ){
            if( !isset( $all[ $i ] ) ){
                return false;
            }
        }
        return true;
    }

    $arr = array();
    for( $i = 1; $i < 300; ++$i ){
        for( $j = 100; $j < 10000; ++$j ){
            if( isPandigital( $i, $j, $i * $j ) ){
                echo $i . " * " . $j . " = " . ( $i * $j ) . "\n";
                $arr[ $i * $j ] = true;
            }
        }
    }
    $sum = 0;
    foreach( $arr as $i => $j ){
        $sum += $i;
    }
    echo $sum;
?>
