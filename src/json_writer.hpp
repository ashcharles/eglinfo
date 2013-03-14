#ifndef EGLINFO_JSON_WRITER_HPP
#define EGLINFO_JSON_WRITER_HPP

#include <iostream>
#include "json-sax/json.h"
#include "writer.hpp"


namespace eglinfo
{


class json_writer:
	public writer
{
public:
	explicit json_writer(std::ostream &p_out);
	~json_writer();

	virtual void begin_write();
	virtual void end_write();
	
	virtual void begin_api(EGLenum const p_api, char const *p_api_name);
	virtual void end_api();
	virtual void next_api();

	virtual void begin_egl_info();
	virtual void end_egl_info();
	virtual void write_main_egl_info(
		  EGLint const p_major_version, EGLint const p_minor_version
		, char const *p_vendor
		, char const *p_version
		, char const *p_client_APIs
		, char const *p_extensions
	);
	virtual void begin_write_egl_configs(EGLint const p_num_configs);
	virtual void write_egl_config(egl_config const &p_egl_config);
	virtual void end_write_egl_configs();
	virtual void write_no_egl_configs();

	virtual void write_main_glapi_info(
		  EGLenum const p_api
		, char const *p_api_name
		, char const *p_version
		, char const *p_renderer
		, char const *p_extensions
	);

	virtual void write_glapi_stats(
		  EGLenum const p_api
		, char const *p_api_name
		, glapi_stats const &p_stats
	);

	virtual void write_main_vg_info(
		  char const *p_vendor
		, char const *p_version
		, char const *p_renderer
		, char const *p_extensions
	);

	virtual void begin_write_vg_image_format_acceleration();
	virtual void write_vg_image_format_acceleration(
		  int const p_format
		, char const *p_name
		, bool const p_accelerated
	);
	virtual void end_write_vg_image_format_acceleration();
	
	virtual void write_vg_path_datatype_acceleration(
		  bool const p_signed8
		, bool const p_signed16
		, bool const p_signed32
		, bool const p_float
	);


private:
	std::ostream &m_out;
	json_printer m_printer;
	bool m_ok;
};


} // namespace eglinfo end


#endif

