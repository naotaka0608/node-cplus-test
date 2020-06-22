#include <napi.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <chrono>
// #include <sys/time.h>

using namespace Napi;

#include "./CalcTest/CalcSquare.h"
#include "./CalcTest/CalcTriangle.h"
#include "./CalcTest/SortLib.h"

Value
CalcSquareJS( const CallbackInfo& info ) {

    Env env = info.Env();

    if ( info.Length() < 2 ) {
        TypeError::New( env, "Wrong number of arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    if ( !info[ 0 ].IsNumber() || !info[ 1 ].IsNumber() ) {
        TypeError::New( env, "Wrong arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }


    // 四角形の面積を求める
    CalcSquare calcSquare;

    double height, width, ans;

    height = info[ 0 ].As<Number>().DoubleValue();
    width = info[ 1 ].As<Number>().DoubleValue();
    
    calcSquare.SetHeight(height);
    calcSquare.SetWidth(width);

    calcSquare.ClacArea();

    ans = calcSquare.GetSquareArea();

    return Number::New(
        env,   
        ans
    );
}

Value
CalcTriangleJS( const CallbackInfo& info ) {

    Env env = info.Env();

    if ( info.Length() < 2 ) {
        TypeError::New( env, "Wrong number of arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }

    if ( !info[ 0 ].IsNumber() || !info[ 1 ].IsNumber() ) {
        TypeError::New( env, "Wrong arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    }
    

    // 三角形の面積を求める
    CalcTriangle calcTriangle;

    double bottom, height, ans;

    bottom = info[ 0 ].As<Number>().DoubleValue();
    height = info[ 1 ].As<Number>().DoubleValue();
    
    calcTriangle.SetBottom(bottom);
    calcTriangle.SetHeight(height);

    calcTriangle.ClacArea();

    ans = calcTriangle.GetTriangleArea();

    return Number::New(
        env,   
        ans
    );
}


Napi::Array QuickSortJS( const CallbackInfo& info ) {
// napi_value QuickSortJS(napi_env env,  const napi_callback_info& info ) {

    Napi::Env env = info.Env();
    Napi::Object obj = Napi::Object::New(env);

    // if ( info.Length() < 2 ) {
    //     TypeError::New( env, "Wrong number of arguments" ).ThrowAsJavaScriptException();
    //     return env.Null();
    // }

    // if ( !info[ 0 ].IsNumber() || !info[ 1 ].IsNumber() ) {
    //     TypeError::New( env, "Wrong arguments" ).ThrowAsJavaScriptException();
    //     return env.Null();
    // }
    

    SortLib sortLib;

    const int max_value = 100;

    int array[max_value];
    int start, end;

    // napi_status status; 
    // size_t argc = 1;
    // napi_value argv[1];
    // status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);  
    // status = napi_get_value_int32(env, argv[0], array);

    Array a = info[ 0 ].As<Array>();
    for(int i = 0; i<a.Length(); i++){
      Napi::Value v = a[i];
      if (v.IsNumber())
      {
        array[i] = (int)v.As<Napi::Number>();
      }
    }

    start = info[ 1 ].As<Number>().DoubleValue();
    end = info[ 2 ].As<Number>().DoubleValue();

    // std::cout << start << std::endl;        
    // std::cout << end << std::endl;        

    sortLib.QuickSort(array, start, end);
    
    // status = napi_create_array(env, array, &array);
    Napi::Array outputArray = Napi::Array::New(env, max_value);
    for (int i = 0; i < max_value; i++) {
        outputArray[i] = Napi::Number::New(env, double(array[i]));
    }
    return outputArray;
    
    // return array;
    // return Array::New(
    //     env,   
    //     array
    // );

}



/*
void QuickSortJS( const CallbackInfo& info ) {

    // Env env = info.Env();

    // if ( info.Length() < 2 ) {
    //     TypeError::New( env, "Wrong number of arguments" ).ThrowAsJavaScriptException();
    //     return env.Null();
    // }

    // if ( !info[ 0 ].IsNumber() || !info[ 1 ].IsNumber() ) {
    //     TypeError::New( env, "Wrong arguments" ).ThrowAsJavaScriptException();
    //     return env.Null();
    // }
    

    SortLib sortLib;

    const int max_value = 100;

    int array[max_value] = 
	{ 
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
	};
    int start, end;

    start = 0;
    end = max_value-1;

    // for(int i=0; i<max_value; i++){
    //     std::cout << array[i];
    // }
    // std::cout << std::endl;
    // const clock_t start_t = clock();
    
    sortLib.QuickSort(array, start, end);

    // const clock_t end_t = clock();

    // std::cout << "C++ duration = " << (double) (end_t - start_t) / CLOCKS_PER_SEC << "sec.\n";

    // for(int i=0; i<max_value; i++){
    //     std::cout << array[i];
    // }
    // std::cout << std::endl;

}
*/


Object
Init( Env env, Object exports ) {
    exports.Set( String::New( env, "calcSquareJS" ), Function::New( env, CalcSquareJS ) );
    exports.Set( String::New( env, "calcTriangleJS" ), Function::New( env, CalcTriangleJS ) );
    exports.Set( String::New( env, "quickSortJS" ), Function::New( env, QuickSortJS ) );
    
    return exports;
}

NODE_API_MODULE( addon, Init )