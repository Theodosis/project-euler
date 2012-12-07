<?php
    function factorial( $num ){
        //return $num == 1 ? 1 : $num * factorial( $num - 1 );
        switch( $num ){
            case 0:
                return 1;
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 6;
            case 4:
                return 24;
            case 5:
                return 120;
            case 6:
                return 720;
            case 7:
                return 5040;
            case 8:
                return 40320;
            case 9:
                return 362880;
        }
    }

    function SumOfFactorialDigits( $num ){
        $sum = 0;
        foreach( str_split( $num ) as $i ){
            $sum += factorial( intval( $i ) );
        }
        return $sum;
    }
    function SumOfDigits( $num ){
        $sum = 0;
        foreach( str_split( $num ) as $i ){
            $sum += $i;
        }
        return $sum;
    }

    $sum = 0;
    for( $i = 3; $i < 100000; ++$i ){
        $fact = SumOfFactorialDigits( $i );
        //$digi = SumOfDigits( $i );
        if( $fact == $i ){
            $sum += $i;
            echo "$i, fact: $fact\n";
        }
    }
    echo "result: $sum\n";
?>
