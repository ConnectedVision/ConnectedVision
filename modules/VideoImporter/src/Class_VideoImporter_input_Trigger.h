/**
* Connected Vision - https://github.com/ConnectedVision
* MIT License
*/

// auto-generated header by CodeFromTemplate - Connected Vision - https://github.com/ConnectedVision
// CodeFromTemplate Version: 0.3 alpha
// Class_VideoImporter_input_Trigger.h
// This file contains the business logic.
// It is generated once and will NOT be OVERWRITTEN by CodeFromTemplate.

#ifndef Class_VideoImporter_input_Trigger_def
#define Class_VideoImporter_input_Trigger_def

#include "stubs/Stub_VideoImporter_input_Trigger.h"

namespace ConnectedVision {
namespace Module {
namespace VideoImporter {

// if you want to extend the auto-generated class, enable the line below
//#define Class_VideoImporter_input_Trigger_extended

#ifdef Class_VideoImporter_input_Trigger_extended
/**
 * Class_VideoImporter_input_Trigger
 * 
 * module: VideoImporter
 * description: Trigger pulse used as signal for the generation of a bounding box.
 */
class Class_VideoImporter_input_Trigger : public Stub_VideoImporter_input_Trigger {

public:
	Class_VideoImporter_input_Trigger() {};
	Class_VideoImporter_input_Trigger(const ::rapidjson::Value& value) : Stub_VideoImporter_input_Trigger(value) {};
	Class_VideoImporter_input_Trigger(const std::string& str) : Stub_VideoImporter_input_Trigger(str) {};
	virtual ~Class_VideoImporter_input_Trigger() {};

 // TODO --> Your declarations and code comes HERE! <--

};
typedef boost::shared_ptr<Class_VideoImporter_input_Trigger> Class_VideoImporter_input_Trigger_p;
#endif // Class_VideoImporter_input_Trigger_extended

} // namespace VideoImporter
} // namespace Module
} // namespace ConnectedVision

#include "stubs/Class_VideoImporter_input_Trigger_Default.h"

#endif // Class_VideoImporter_input_Trigger_def