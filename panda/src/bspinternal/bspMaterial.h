/**
 * PANDA3D BSP LIBRARY
 *
 * Copyright (c) Brian Lach <brianlach72@gmail.com>
 * All rights reserved.
 *
 * @file bsp_material.h
 * @author Brian Lach
 * @date November 02, 2018
 */

#ifndef BSP_MATERIAL_H
#define BSP_MATERIAL_H

#include "config_bspinternal.h"
#include "notifyCategoryProxy.h"
#include "simpleHashMap.h"
#include "pointerTo.h"
#include "typedReferenceCount.h"

#define DEFAULT_SHADER	"UnlitNoMat"

NotifyCategoryDecl(bspmaterial, EXPCL_BSPINTERNAL, EXPTP_BSPINTERNAL);

class EXPCL_BSPINTERNAL BSPMaterial : public TypedReferenceCount
{
PUBLISHED:
  INLINE explicit BSPMaterial(const std::string &name = DEFAULT_SHADER) :
    TypedReferenceCount(),
    _has_env_cubemap(false),
    _cached_env_cubemap(false),
    _has_transparency(false),
    _shader_name(name),
    _surfaceprop("default"),
    _contents("solid"),
    _has_bumpmap(false),
    _lightmapped(false),
    _skybox(false) {
  }

  INLINE BSPMaterial(const BSPMaterial &copy) :
    TypedReferenceCount(copy),
    _shader_name(copy._shader_name),
    _shader_keyvalues(copy._shader_keyvalues),
    _file(copy._file),
    _has_env_cubemap(copy._has_env_cubemap),
    _cached_env_cubemap(copy._cached_env_cubemap),
    _surfaceprop(copy._surfaceprop),
    _contents(copy._contents),
    _has_transparency(copy._has_transparency),
    _lightmapped(copy._lightmapped),
    _has_bumpmap(copy._has_bumpmap),
    _skybox(copy._skybox) {
  }

  INLINE void operator = (const BSPMaterial &copy) {
    TypedReferenceCount::operator = (copy);
    _shader_name = copy._shader_name;
    _shader_keyvalues = copy._shader_keyvalues;
    _file = copy._file;
    _has_env_cubemap = copy._has_env_cubemap;
    _cached_env_cubemap = copy._cached_env_cubemap;
    _surfaceprop = copy._surfaceprop;
    _contents = copy._contents;
    _has_transparency = copy._has_transparency;
    _lightmapped = copy._lightmapped;
    _has_bumpmap = copy._has_bumpmap;
    _skybox = copy._skybox;
  }

  INLINE void set_keyvalue(const std::string &key, const std::string &value) {
    _shader_keyvalues[key] = value;
  }
  INLINE std::string get_keyvalue(const std::string &key) const {
    return _shader_keyvalues.get_data(_shader_keyvalues.find(key));
  }
  INLINE size_t get_num_keyvalues() const {
    return _shader_keyvalues.size();
  }
  INLINE const std::string &get_key(size_t i) const {
    return _shader_keyvalues.get_key(i);
  }
  INLINE const std::string &get_value(size_t i) const {
    return _shader_keyvalues.get_data(i);
  }

  INLINE int get_keyvalue_int(const std::string &key) const {
    return atoi(get_keyvalue(key).c_str());
  }
  INLINE float get_keyvalue_float(const std::string &key) const {
    return atof(get_keyvalue(key).c_str());
  }

  INLINE void set_shader(const std::string &shader_name) {
    _shader_name = shader_name;
  }
  INLINE std::string get_shader() const {
    return _shader_name;
  }

  INLINE Filename get_file() const {
    return _file;
  }

  INLINE bool has_keyvalue(const std::string &key) const {
    return _shader_keyvalues.find(key) != -1;
  }

  INLINE bool has_env_cubemap() const {
    return _has_env_cubemap;
  }

  INLINE bool has_transparency() const {
    return _has_transparency;
  }

  INLINE std::string get_surface_prop() const {
    return _surfaceprop;
  }

  INLINE std::string get_contents() const {
    return _contents;
  }

  INLINE bool is_lightmapped() const {
    return _lightmapped;
  }

  INLINE bool is_skybox() const {
    return _skybox;
  }

  INLINE bool has_bumpmap() const {
    return _has_bumpmap;
  }

  static const BSPMaterial *get_from_file(const Filename &file);
  static const BSPMaterial *get_default_material();

private:
  Filename _file;
  std::string _shader_name;
  bool _has_env_cubemap;
  bool _cached_env_cubemap;
  bool _has_transparency;
  bool _lightmapped;
  bool _skybox;
  bool _has_bumpmap;
  std::string _surfaceprop;
  std::string _contents;
  SimpleHashMap<std::string, std::string, string_hash> _shader_keyvalues;

  typedef SimpleHashMap<std::string, CPT(BSPMaterial), string_hash> materialcache_t;
  static materialcache_t _material_cache;

  static PT(BSPMaterial) _default_material;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    TypedReferenceCount::init_type();
    register_type(_type_handle, "BSPMaterial",
                  TypedReferenceCount::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {
    init_type(); return get_class_type();
  }

private:
  static TypeHandle _type_handle;
};

#endif // BSP_MATERIAL_H
