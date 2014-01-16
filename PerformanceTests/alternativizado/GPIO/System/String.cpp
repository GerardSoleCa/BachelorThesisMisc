#include "Object.h"
#include "String.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

namespace System{

	String::String() {
		Data = new char[0];
		Length = 0;
	}

	String::String(int val) {	
		char* tmp = new char[33];
		sprintf(tmp, "%d", val);
		Length = strlen(tmp);
		Data = new char[Length];
		memcpy(Data, tmp, Length);
		delete tmp;
	}

	String::String(long val) {	
		char* tmp = new char[66];
		sprintf(tmp, "%ld", val);
		Length = strlen(tmp);
		Data = new char[Length];
		memcpy(Data, tmp, Length);
		delete tmp;
	}

	String::String(char txt) {
	
		Length = 1;
		Data = new char[1];
		Data[0] = txt;
	}

	String::String(const char* txt) {
		//TODO It will be nice to not to copy "constant" strings 
		Length = strlen(txt);
		Data = new char[Length+1];
		strncpy(Data,txt,Length);
	}

	String::String(Array<char>* txt) {
		Length = txt->Length;
		Data = *txt;
	}

	Array<char>* String::ToCharArray()
	{
		return new Array<char>(Data, Length);
	}

	String* String::operator=(char* text) {
		String* s = new String(text);
		return s;
	}

	String::operator const char*()
	{
		return Data;
	}

	String::operator char*()
	{
		return Data;
	}

	String::~String() {
		if(Data!=null) {
			delete Data;
			Data = null;
		}
	}	
	String* String::Concat(Array<String>* elements) {
		//std::cout << "Concat string" << std::endl;
		//String* newstring = new String();

		//int totalLength = 0;
		//for(int i = 0; i < elements->Length; i++)
		//{
		//	totalLength += (*elements)[i]->Length;
		//	std::cout << "size:" << totalLength << std::endl;
		//	//std::cout << totalLength << std::endl;
		//	//totalLength += (*elements)[i]->Length;
		//}
		//newstring->Data = new char[totalLength];
		std::stringstream ss;
		for(int i = 0; i < elements->Length; i++)
		{
			String* s = (*elements)[i];
			//std::cout << "string element " << i << std::endl;
			//std::cout << s->Data << std::endl;
			//strncpy(newstring->Data + newstring->Length, s->Data, s->Length);
			//memcpy(newstring->Data + newstring->Length, s->Data, s->Length);
			ss << s->Data;
			//newstring->Length += s->Length;
			//delete s;
		}                
//		const char* finalData = ss.str().data();
		String* newstring = new String(ss.str().data());
		//delete elements;
		//std::cout << "RESULT CONCAT: " << newstring->Data << std::endl;
		return newstring;
	}

	String* String::Concat(Array<Object>* elements) {
		//std::cout<<"Concat object" << std::endl;
		Array<String>* stringArray = new Array<String>(elements->Length);

		for(int i = 0; i < elements->Length; i++)
		{
			//std::cout << "Convert object " << i << std::endl;
			
			Object* tmp = (*elements)[i];
                        String* tmp_s;
                        if(is_inst_of<String*>(tmp))
                        {
			    tmp_s = (String*)tmp;
                        }
                        else
                        {
                            tmp_s = tmp->ToString();
                        }
			//std::cout << "converted " << tmp_s->Data << std::endl;
			stringArray->SetData(i , tmp_s);
		}
		//delete elements;
		return Concat(stringArray);
	}	

	char* stoupper( char* s )
	{
		char* p = s;
  		while (*p = toupper( *p )) p++;
  		return s;
	}	

	char* stolower( char* s )
	{
		char* p = s;
  		while (*p = tolower( *p )) p++;
  		return s;
  	}	
	
	String* String::ToLower()
	{
		String* resString = new String(stolower(Data));
		return resString;
	}

	String* String::ToUpper()
	{
		String* resString = new String(stoupper(Data));
		return resString;
	}

	String* String::ToString()
	{
		return this;
	}
}
