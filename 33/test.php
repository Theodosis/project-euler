<?php
    $A = 1;
    $B = 1;
    for( $i = 10; $i < 100; ++$i ){
        for( $j = $i; $j < 100; ++$j ){
            if( $i == $j ){
                continue;
            }
            $J = "" . $j;
            $I = "" . $i;
            if( $J[ 0 ] == $I [ 0 ] && $J[ 0 ] != 0 ){
                $a = intval( $I[ 1 ] );
                $b = intval( $J[ 1 ] );
                if( $b == 0 ){
                    continue;
                }
                if( $i / $j == $a / $b ){
                    $A *= $a;
                    $B *= $b;
                    continue;
                }
            }
            if( $J[ 0 ] == $I [ 1 ] && $J[ 0 ] != 0 ){
                $a = intval( $I[ 0 ] );
                $b = intval( $J[ 1 ] );
                if( $b == 0 ){
                    continue;
                }
                if( $i / $j == $a / $b ){
                    $A *= $a;
                    $B *= $b;
                    continue;
                }
            }
            if( $J[ 1 ] == $I [ 0 ] && $J[ 1 ] != 0 ){
                $a = intval( $I[ 1 ] );
                $b = intval( $J[ 0 ] );
                if( $b == 0 ){
                    continue;
                }
                if( $i / $j == $a / $b ){
                    $A *= $a;
                    $B *= $b;
                    continue;
                }
            }
            if( $J[ 1 ] == $I [ 1 ] && $J[ 1 ] != 0 ){
                $a = intval( $I[ 0 ] );
                $b = intval( $J[ 0 ] );
                if( $b == 0 ){
                    continue;
                }
                if( $i / $j == $a / $b ){
                    $A *= $a;
                    $B *= $b;
                    continue;
                }
            }
        }
    }
    echo $B/$A;
?>
