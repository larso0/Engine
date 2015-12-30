/* 
 * File:   Metadata.h
 * Author: larso
 *
 * Created on 29. desember 2015, 01:01
 */

#ifndef METADATA_H
#define METADATA_H

#include <string>

class Metadata
{
public:
	Metadata(std::string type) : super(nullptr), type(type) {}
	Metadata(Metadata* super, std::string type) : super(super), type(type) {}
	inline bool instanceOf(std::string type)
	{
		Metadata* tmp = this;
		for(; tmp != nullptr && tmp->type != type; tmp = tmp->super);
		return tmp != nullptr;
	}
private:
	Metadata* super;
	std::string type;
};

#define DECLARE_META(type) extern Metadata meta ## type
#define DEFINE_META(type) Metadata meta ## type(#type)
#define DEFINE_META_INHERIT(type, super) Metadata meta ## type(&meta ## super, #type)
#define DECLARE_META_PTR(type) public: Metadata* meta = &meta ## type
#define INHERIT_META_PTR(type) meta = &meta ## type
#define INSTANCE_OF(objectptr, type) (objectptr)->meta->instanceOf(#type)

#endif /* METADATA_H */

