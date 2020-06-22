var addon = require( './build/Release/addon' );
const microtime = require("microtime");

// var a = 3.0;
// var b = 5.0;

// console.log( "四角形の面積は  " + addon.calcSquareJS( a, b ) );
// console.log( "三角形の面積は  " + addon.calcTriangleJS( a, b ) );

// let array = [6,3,5,7,1,4,8,9,5,3,2];
// let array = [3,7,2,4,5,1,9,8,5];

// console.info(addon.quickSortJS(array, 0, array.length-1));

// console.info(addon.quickSortJS(array, 0, array.length-1));


{
    let array = 
    [
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10
    ];
    console.info(array);   
    
    const start = microtime.now();

    let array2 = addon.quickSortJS(array, 0, array.length-1);
    // addon.quickSortJS();

    console.info(microtime.now() - start);   
    console.info(array2);   

}