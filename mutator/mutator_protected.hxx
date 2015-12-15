#ifndef MUTATOR_PROTECTED_INCLUDED
#define MUTATOR_PROTECTED_INCLUDED

#include <vector>
#include <map>

//============================================================================
// Scalar
//============================================================================

#define P_BUILTIN(TYPE, NAME) \
TYPE m_ ## NAME; \
protected: \
const TYPE NAME() const {return m_ ## NAME;} \
TYPE NAME() {return m_ ## NAME;} \
void set_ ## NAME(const TYPE NAME) {m_ ## NAME = NAME;} \
private:

#define P_INSTANCE(TYPE, NAME) \
TYPE m_ ## NAME; \
protected: \
const TYPE & NAME() const {return m_ ## NAME;} \
TYPE & NAME() {return m_ ## NAME;} \
void set_ ## NAME(const TYPE & NAME) {m_ ## NAME = NAME;} \
private:

//============================================================================
// Vector
//============================================================================

#define P_BUILTIN_VECTOR(TYPE, NAME) \
std::vector<TYPE> m_ ## NAME; \
protected: \
const std::vector<TYPE> & NAME() const {return m_ ## NAME;} \
std::vector<TYPE> & NAME() {return m_ ## NAME;} \
const TYPE NAME(size_t i) const {return m_ ## NAME[i];} \
void set_ ## NAME(size_t i, const TYPE value) {m_ ##NAME[i] = value;} \
private:

#define P_INSTANCE_VECTOR(TYPE, NAME) \
std::vector<TYPE> m_ ## NAME; \
protected: \
const std::vector<TYPE> & NAME() const { return m_ ## NAME;} \
std::vector<TYPE> & NAME() { return m_ ## NAME;} \
const TYPE & NAME(size_t i) const { return m_ ## NAME[i];} \
TYPE & NAME(size_t i) { return m_ ## NAME[i];} \
void set_ ## NAME(const size_t i, const TYPE & value) {m_ ##NAME[i] = value;} \
private:

//============================================================================
// Map
//============================================================================

#define P_BUILTIN_MAP(KEY_TYPE, VALUE_TYPE, NAME) \
std::map< KEY_TYPE, VALUE_TYPE > m_ ## NAME; \
protected: \
const std::map< KEY_TYPE, VALUE_TYPE > & NAME() const { return m_ ## NAME;} \
std::map< KEY_TYPE, VALUE_TYPE > & NAME() { return m_ ## NAME;} \
const VALUE_TYPE NAME(const KEY_TYPE & key) { return m_ ## NAME[key];} \
void set_ ## NAME(const KEY_TYPE & key, const VALUE_TYPE value) {m_ ## NAME[key] = value;} \
private:

#define P_INSTANCE_MAP(KEY_TYPE, VALUE_TYPE, NAME) \
std::map< KEY_TYPE, VALUE_TYPE > m_ ## NAME; \
protected: \
const std::map< KEY_TYPE, VALUE_TYPE > & NAME() const { return m_ ## NAME;} \
std::map< KEY_TYPE, VALUE_TYPE > & NAME() { return m_ ## NAME;} \
VALUE_TYPE & NAME(const KEY_TYPE & key) { return m_ ## NAME[key];} \
void set_ ## NAME(const KEY_TYPE & key, const VALUE_TYPE & value) {m_ ## NAME[key] = value;} \
private:

//============================================================================
// ndarray
//============================================================================

#define P_ARRAY1D(NAME) \
array1d_t m_ ## NAME; \
protected: \
const array1d_t & NAME() const {return m_ ## NAME;} \
array1d_t & NAME() { return m_ ## NAME;} \
const double NAME(const size_t i) const {return m_ ## NAME(i);} \
double NAME(const size_t i) {return m_ ## NAME(i);} \
void set_ ## NAME(const size_t i, const double value) {m_ ##NAME(i) = value;} \
private:

#define P_ARRAY2D(NAME) \
protected: \
const array2d_t & NAME() const {return m_ ## NAME;} \
array2d_t & NAME() { return m_ ## NAME;} \
const double NAME(const size_t i0, const size_t i1) const {return m_ ## NAME(i0,i1);} \
double NAME(const size_t i0, const size_t i1) {return m_ ## NAME(i0,i1);} \
void set_ ## NAME(const size_t i0, const size_t i1, const double value) {m_ ##NAME(i0,i1) = value;} \
private:

#endif
