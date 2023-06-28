void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void CONTROLADOR_init__(CONTROLADOR *data__, BOOL retain) {
  __INIT_VAR(data__->SP,0,retain)
  __INIT_VAR(data__->PV,0,retain)
  __INIT_VAR(data__->KP,1700,retain)
  __INIT_VAR(data__->TR,2500,retain)
  __INIT_VAR(data__->R1,0,retain)
  __INIT_VAR(data__->CV,0,retain)
  __INIT_VAR(data__->STATE,0,retain)
  INTEGRAL_init__(&data__->INTEGRAL0,retain);
  __INIT_VAR(data__->ITERM,0,retain)
  __INIT_VAR(data__->CYCLE,0,retain)
  __INIT_VAR(data__->ERROR,0,retain)
  __INIT_VAR(data__->OUTMAX,6000.0,retain)
  __INIT_VAR(data__->OUTMIN,0.0,retain)
  __INIT_VAR(data__->_TMP_UINT_TO_REAL17_OUT,0,retain)
  __INIT_VAR(data__->_TMP_UINT_TO_REAL41_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV28_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV27_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD26_OUT,0,retain)
  __INIT_VAR(data__->_TMP_UINT_TO_REAL13_OUT,0,retain)
  __INIT_VAR(data__->_TMP_UINT_TO_REAL25_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL6_OUT,0,retain)
  __INIT_VAR(data__->_TMP_LIMIT36_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ39_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL34_OUT,0,retain)
  __INIT_VAR(data__->_TMP_UINT_TO_REAL14_OUT,0,retain)
  __INIT_VAR(data__->_TMP_UINT_TO_REAL20_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV18_OUT,0,retain)
  __INIT_VAR(data__->_TMP_REAL_TO_TIME16_OUT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->_TMP_REAL_TO_UINT30_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SEL4_OUT,0,retain)
  __INIT_VAR(data__->_TMP_UINT_TO_REAL12_OUT,0,retain)
  __INIT_VAR(data__->_TMP_UINT_TO_REAL5_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB9_OUT,0,retain)
}

// Code part
void CONTROLADOR_body__(CONTROLADOR *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_UINT_TO_REAL17_OUT,,UINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->TR,)));
  __SET_VAR(data__->,_TMP_UINT_TO_REAL41_OUT,,UINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)100));
  __SET_VAR(data__->,_TMP_DIV28_OUT,,DIV__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_UINT_TO_REAL17_OUT,),
    (REAL)__GET_VAR(data__->_TMP_UINT_TO_REAL41_OUT,)));
  __SET_VAR(data__->,_TMP_DIV27_OUT,,DIV__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->ITERM,),
    (REAL)__GET_VAR(data__->_TMP_DIV28_OUT,)));
  __SET_VAR(data__->,_TMP_ADD26_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_DIV27_OUT,),
    (REAL)__GET_VAR(data__->ERROR,)));
  __SET_VAR(data__->,_TMP_UINT_TO_REAL13_OUT,,UINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->KP,)));
  __SET_VAR(data__->,_TMP_UINT_TO_REAL25_OUT,,UINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)100));
  __SET_VAR(data__->,_TMP_DIV10_OUT,,DIV__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_UINT_TO_REAL13_OUT,),
    (REAL)__GET_VAR(data__->_TMP_UINT_TO_REAL25_OUT,)));
  __SET_VAR(data__->,_TMP_MUL6_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_ADD26_OUT,),
    (REAL)__GET_VAR(data__->_TMP_DIV10_OUT,)));
  __SET_VAR(data__->,_TMP_LIMIT36_OUT,,LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->OUTMIN,),
    (REAL)__GET_VAR(data__->_TMP_MUL6_OUT,),
    (REAL)__GET_VAR(data__->OUTMAX,)));
  __SET_VAR(data__->,_TMP_EQ39_OUT,,EQ__BOOL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_MUL6_OUT,),
    (REAL)__GET_VAR(data__->_TMP_LIMIT36_OUT,)));
  __SET_VAR(data__->,_TMP_SEL34_OUT,,SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ39_OUT,),
    (REAL)0.0,
    (REAL)__GET_VAR(data__->ERROR,)));
  __SET_VAR(data__->,_TMP_UINT_TO_REAL14_OUT,,UINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)500));
  __SET_VAR(data__->,_TMP_UINT_TO_REAL20_OUT,,UINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)1000));
  __SET_VAR(data__->,_TMP_DIV18_OUT,,DIV__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_UINT_TO_REAL14_OUT,),
    (REAL)__GET_VAR(data__->_TMP_UINT_TO_REAL20_OUT,)));
  __SET_VAR(data__->,_TMP_REAL_TO_TIME16_OUT,,REAL_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_DIV18_OUT,)));
  __SET_VAR(data__->INTEGRAL0.,RUN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->INTEGRAL0.,XIN,,__GET_VAR(data__->_TMP_SEL34_OUT,));
  __SET_VAR(data__->INTEGRAL0.,CYCLE,,__GET_VAR(data__->_TMP_REAL_TO_TIME16_OUT,));
  INTEGRAL_body__(&data__->INTEGRAL0);
  __SET_VAR(data__->,ITERM,,__GET_VAR(data__->INTEGRAL0.XOUT,));
  __SET_VAR(data__->,_TMP_REAL_TO_UINT30_OUT,,REAL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_LIMIT36_OUT,)));
  __SET_VAR(data__->,_TMP_SEL4_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->_TMP_REAL_TO_UINT30_OUT,),
    (UINT)__GET_VAR(data__->SP,)));
  __SET_VAR(data__->,CV,,__GET_VAR(data__->_TMP_SEL4_OUT,));
  __SET_VAR(data__->,_TMP_UINT_TO_REAL12_OUT,,UINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->SP,)));
  __SET_VAR(data__->,_TMP_UINT_TO_REAL5_OUT,,UINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->PV,)));
  __SET_VAR(data__->,_TMP_SUB9_OUT,,SUB__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_UINT_TO_REAL12_OUT,),
    (REAL)__GET_VAR(data__->_TMP_UINT_TO_REAL5_OUT,)));
  __SET_VAR(data__->,ERROR,,__GET_VAR(data__->_TMP_SUB9_OUT,));

  goto __end;

__end:
  return;
} // CONTROLADOR_body__() 





