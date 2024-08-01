#ifndef ZEPHLIX_OBJ_H
#define ZEPHLIX_OBJ_H


#include "common.h" 
#include "value.h" 
#include "chunk.h"

#define OBJ_TYPE(value)        (AS_OBJ(value)->type) 

#define IS_STRING(value)       isObjType(value, OBJ_STRING) 
#define AS_STRING(value)       ((ObjString*)AS_OBJ(value)) 
#define AS_CSTRING(value)      (((ObjString*)AS_OBJ(value))->chars) 
#define IS_FUNCTION(value)     isObjType(value, OBJ_FUNCTION)
#define AS_FUNCTION(value)     ((ObjFunction*)AS_OBJ(value))

typedef  enum  {
   OBJ_STRING ,
   OBJ_FUNCTION
}  ObjType ;

struct  Obj  {
   ObjType  type ;
 struct Obj* next;
};



typedef struct {
  Obj obj;
  int arity;
  Chunk chunk;
  ObjString* name;
} ObjFunction;

struct  ObjString  {
   Obj  obj ;
   int  length ;
   char *  chars ;
     uint32_t hash;
};
ObjFunction* newFunction();

ObjString* takeString(char* chars, int length);

ObjString *  copyString ( const  char *  chars ,  int  length );
void printObject(Value value);

static  inline  bool  isObjType ( Value  value ,  ObjType  type ) {
   return  IS_OBJ ( value ) &&  AS_OBJ ( value )-> type  ==  type ;
}
 
 #endif 