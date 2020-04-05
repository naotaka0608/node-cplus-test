#include <napi.h>

using namespace Napi;

#include "./CalcTest/CalcSquare.h"
#include "./CalcTest/CalcTriangle.h"


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

Object
Init( Env env, Object exports ) {
    exports.Set( String::New( env, "calcSquareJS" ), Function::New( env, CalcSquareJS ) );
    exports.Set( String::New( env, "calcTriangleJS" ), Function::New( env, CalcTriangleJS ) );
    return exports;
}

NODE_API_MODULE( addon, Init )