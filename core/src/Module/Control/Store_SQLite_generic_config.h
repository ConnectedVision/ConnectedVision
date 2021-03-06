/**
* Connected Vision - https://github.com/ConnectedVision
* MIT License
*/

// auto-generated header by CodeFromTemplate - Connected Vision - https://github.com/ConnectedVision
// CodeFromTemplate Version: 0.3 alpha
// Store_SQLite_generic_config.h
// This file implements the IStore interface for SQLite access.
// It is generated once and will NOT be OVERWRITTEN by CodeFromTemplate.
#ifndef Store_SQLite_generic_config_def
#define Store_SQLite_generic_config_def

#include "stubs/Store_SQLite_Stub_generic_config.h"

namespace ConnectedVision {
namespace DataHandling {

// if you want to extend the auto-generated class, enable the line below
//#define Store_SQLite_generic_config_extended

#ifdef Store_SQLite_generic_config_extended
/**
 * Store_SQLite_generic_config
 *
 * module: 
 * description: config chain
 */
class Store_SQLite_generic_config : public Store_SQLite_Stub_generic_config {
public:
	/**
	* constructor
	*/
	Store_SQLite_generic_config(
		const id_t& configID,			///< [in] config ID
		DBConnection& db				///< [in] DB connection object
	) : Store_SQLite_Stub_generic_config ( configID, db )
	{}

	/*
	* virtual destructor
	*/
	virtual ~Store_SQLite_generic_config()
	{}

 // TODO --> Your declarations and code comes HERE! <--

};
#endif // Store_SQLite_generic_config_extended


// if you want to extend the auto-generated class, enable the line below
//#define Store_SQLite_Factory_generic_config_extended

#ifdef Store_SQLite_Factory_generic_config_extended
/**
 * factory for Store_SQLite_generic_config
 */
class Store_SQLite_Factory_generic_config : public Store_SQLite_Factory_Stub_generic_config {
public:
	/**
	* constructor
	*/
	Store_SQLite_Factory_generic_config(
		DBConnection& db				///< [in] DB connection object
	) : Store_SQLite_Factory_Stub_generic_config ( db )
	{}

	/*
	* virtual destructor
	*/
	virtual ~Store_SQLite_Factory_generic_config()
	{}

 // TODO --> Your declarations and code comes HERE! <--

};
#define Store_SQLite_Factory_generic_config_enabled
#endif // Store_SQLite_Factory_generic_config_extended

} // namespace DataHandling
} // namespace ConnectedVision

#include "stubs/Store_SQLite_generic_config_Default.h"

#endif // Store_SQLite_generic_config_def