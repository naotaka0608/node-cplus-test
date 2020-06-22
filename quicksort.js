const microtime = require("microtime");

function QuickSort(array, left, right){

    let i, j;
    let pivot;

    i = left;
    j = right;

    pivot = array[Math.floor((left + right)/2)];

    while(true){

        while(array[i] < pivot) i++;

        while(pivot < array[j]) j--;

        if(i >= j) break;

        Swap(array, i, j);

        i++;
        j--;

    }

    if(left < (i-1)) QuickSort(array, left, (i-1));

    if((i+1) < right) QuickSort(array, (j+1), right);

}

function Swap(x, i ,j){
    let temp;
    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

{
    let test1 = 
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

    const start1 = microtime.now();

    QuickSort(test1, 0, test1.length-1);
    
    console.info(microtime.now() - start1);    
    console.info(test1);
}


{
    let test2 = 
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

    const start2 = microtime.now();

    test2.sort((a, b) => a - b);

    console.info(microtime.now() - start2);
    console.info(test2);
}


var test = true;
if(test){
    var test2 = 5;
}
var test2 = 10;

console.info(test2);
