#pragma once
#include "IEnumerable.h"
#include <stdlib.h>
#include <map>
#include <utility>

using namespace std;
namespace System{
	namespace Collections{
		namespace Generic{
			/*template<typename KeyT, typename ValueT>
			class Dictionary_T : public virtual Object
			{
			
			private:
				TypeDecl(KeyT)* keys;
				TypeDecl(ValueT)* values;
			
			public:
				int Count;
				Dictionary_T()
				{
					Count = 0;
				}
			
				Dictionary_T(Dictionary_T<KeyT, ValueT>* dictionary)
				{
					for(int i=0; i<dictionary->Count;i++)
					{
						TypeDecl(KeyT) key = dictionary->keys[i];
						TypeDecl(ValueT) val = dictionary->values[i];
						this->Add(key,val);
					}
				}
			
				~Dictionary_T()
				{
					Count = 0;
					delete(keys);
					delete(values);
				}				
			
				void Add(TypeDecl(KeyT) key, TypeDecl(ValueT) value)
				{
					if (Count == 0)
					{
						keys = (TypeDecl(KeyT)*)malloc(sizeof(TypeDecl(KeyT)));
						values = (TypeDecl(ValueT)*)malloc(sizeof(TypeDecl(ValueT)));
					}
					else
					{
						keys = (TypeDecl(KeyT)*)realloc(keys, (Count+1)*sizeof(TypeDecl(KeyT)));
						values = (TypeDecl(ValueT)*)realloc(values, (Count+1)*sizeof(TypeDecl(ValueT)));
					}
			
					keys[Count] = key;
					values[Count] = value;

					Count++;
				}

				void SetData(TypeDecl(KeyT) key, TypeDecl(ValueT) value)
				{					
					if(ContainsKey(key))
					{
						(*this)[key] = value;
					}
				}

				bool ContainsKey(TypeDecl(KeyT) key)
				{
					for(int i = 0; i < Count; i++)
					{
						TypeDecl(KeyT) tmp = keys[i];
						if(tmp == key)
						{
							return true;
						}
					}
					return false;
				}

				void Remove(TypeDecl(KeyT) key)
				{
					for(int i = 0; i < Count; i++)
					{
						TypeDecl(KeyT) tmp = (TypeDecl(KeyT))keys[i];
						if(tmp == key)
						{
							for(int j = i; j < Count; j++)
							{
								keys[j] = keys[j+1];
								values[j] = values[j+1];
							}

							keys = (TypeDecl(KeyT)*)realloc(keys, (Count - 1)*sizeof(TypeDecl(KeyT)));
							values = (TypeDecl(ValueT)*)realloc(values, (Count - 1)*sizeof(TypeDecl(ValueT)));

							Count--;
							return;
						}
					}
				}

				TypeDecl(ValueT)& operator[](TypeDecl(KeyT) key)
				{
					for(int i = 0; i < Count; i++)
					{
						TypeDecl(KeyT) tmp = (TypeDecl(KeyT))(keys[i]);
						if(tmp == key)
						{
							return values[i];
						}
					}

					throw new Exception(new String("Key not found"));
				}
			};*/

			template<typename KeyT, typename ValueT>
			class Dictionary_T : private map<TypeDecl(KeyT),TypeDecl(ValueT)>, public Object
			{
				public:
				int Count;

				Dictionary_T() : map<TypeDecl(KeyT),TypeDecl(ValueT)>()
				{
					Count = 0;
				}
			
				Dictionary_T(Dictionary_T<KeyT, ValueT>* dictionary) : map<TypeDecl(KeyT),TypeDecl(ValueT)>()
				{
					for(int i=0; i<dictionary->Count;i++)
					{
						TypeDecl(KeyT) key = dictionary->keys[i];
						TypeDecl(ValueT) val = dictionary->values[i];
						this->Add(key,val);
					}					
				}
			
				~Dictionary_T()
				{
					map<TypeDecl(KeyT),TypeDecl(ValueT)>::clear();
				}				
			
				inline void Add(TypeDecl(KeyT) key, TypeDecl(ValueT) value)
				{
					pair<TypeDecl(KeyT), TypeDecl(ValueT)> mpair(key, value);
					map<TypeDecl(KeyT),TypeDecl(ValueT)>::insert(mpair);
					//map<TypeDecl(KeyT),TypeDecl(ValueT)>::emplace(key, value);
					Count=map<TypeDecl(KeyT),TypeDecl(ValueT)>::size();
				}

				inline void SetData(TypeDecl(KeyT) key, TypeDecl(ValueT) value)
				{	
					map<TypeDecl(KeyT),TypeDecl(ValueT)>::at(key) = value;
				}

				inline bool ContainsKey(TypeDecl(KeyT) key)
				{
					return map<TypeDecl(KeyT),TypeDecl(ValueT)>::find(key) != map<TypeDecl(KeyT),TypeDecl(ValueT)>::end();
				}

				inline void Remove(TypeDecl(KeyT) key)
				{
					map<TypeDecl(KeyT),TypeDecl(ValueT)>::erase(key);
					Count=map<TypeDecl(KeyT),TypeDecl(ValueT)>::size();
				}

				inline TypeDecl(ValueT)& operator[](TypeDecl(KeyT) key)
				{					
					return map<TypeDecl(KeyT),TypeDecl(ValueT)>::at(key);
				}
			};
		}
	}
}
