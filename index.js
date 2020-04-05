var addon = require( './build/Release/addon' );

var a = 3.0;
var b = 5.0;

console.log( "四角形の面積は  " + addon.calcSquareJS( a, b ) );
console.log( "三角形の面積は  " + addon.calcTriangleJS( a, b ) );
