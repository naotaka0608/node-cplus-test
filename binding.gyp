{   "targets":
    [   
        {   
            "target_name"   : "addon",
            
            "sources"       : [ 
                "addon.cpp", 
                "CalcTest/CalcSquare.h",  "CalcTest/CalcSquare.cpp",
                "CalcTest/CalcTriangle.h",  "CalcTest/CalcTriangle.cpp" 
            ],

            "defines"       : [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
            
            "include_dirs"  : [ "<!@(node -p \"require( 'node-addon-api' ).include\")" ]
        }
    ]
}