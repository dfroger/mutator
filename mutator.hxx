#ifndef MUTATOR_INCLUDED
#define MUTATOR_INCLUDED

//============================================================================
// Scalar
//============================================================================

#define M_BUILTIN(TYPE, NAME) \
TYPE m_ ## NAME; \
public: \
const TYPE NAME() const {return m_ ## NAME;} \
TYPE NAME() {return m_ ## NAME;} \
void set_ ## NAME(const TYPE NAME) {m_ ## NAME = NAME;} \
private:

#define M_INSTANCE(TYPE, NAME) \
TYPE m_ ## NAME; \
public: \
const TYPE & NAME() const {return m_ ## NAME;} \
TYPE & NAME() {return m_ ## NAME;} \
void set_ ## NAME(const TYPE & NAME) {m_ ## NAME = NAME;} \
private:

//============================================================================
// Vector
//============================================================================

#define M_BUILTIN_VECTOR(TYPE, NAME) \
std::vector<TYPE> m_ ## NAME; \
public: \
const std::vector<TYPE> & NAME() const {return m_ ## NAME;} \
std::vector<TYPE> & NAME() {return m_ ## NAME;} \
const TYPE NAME(size_t i) const {return m_ ## NAME[i];} \
void set_ ## NAME(size_t i, const TYPE value) {m_ ##NAME[i] = value;}
private:

#define M_INSTANCE_VECTOR(TYPE, NAME) \
std::vector<TYPE> m_ ## NAME; \
public: \
const std::vector<TYPE> & NAME() const { return m_ ## NAME;} \
std::vector<TYPE> & NAME() { return m_ ## NAME;} \
const TYPE & NAME(size_t i) const { return m_ ## NAME[i];} \
TYPE & NAME(size_t i) { return m_ ## NAME[i];} \
void set_ ## NAME(const size_t i, const TYPE & value) {m_ ##NAME[i] = value;}
private:

//============================================================================
// Map
//============================================================================

#define M_BUILTIN_MAP(KEY_TYPE, VALUE_TYPE, NAME) \
std::map< KEY_TYPE, VALUE_TYPE > m_ ## NAME; \
public: \
const std::map< KEY_TYPE, VALUE_TYPE > & NAME() const { return m_ ## NAME;} \
std::map< KEY_TYPE, VALUE_TYPE > & NAME() { return m_ ## NAME;} \
const VALUE_TYPE NAME(const KEY_TYPE & key) const { return m_ ## NAME[key];} \
VALUE_TYPE NAME(const KEY_TYPE & key) { return m_ ## NAME[key];} \
private:

#define M_INSTANCE_MAP(KEY_TYPE, VALUE_TYPE, NAME) \
std::map< KEY_TYPE, VALUE_TYPE > m_ ## NAME; \
public: \
const std::map< KEY_TYPE, VALUE_TYPE > & NAME() const { return m_ ## NAME;} \
std::map< KEY_TYPE, VALUE_TYPE > & NAME() { return m_ ## NAME;} \
const VALUE_TYPE & NAME(const KEY_TYPE & key) const { return m_ ## NAME[key];} \
VALUE_TYPE & NAME(const KEY_TYPE & key) { return m_ ## NAME[key];} \
private:

//============================================================================
// ndarray
//============================================================================

#define M_ARRAY1D(NAME) \
array1d_t m_ ## NAME; \
public: \
const array1d_t & NAME() const {return m_ ## NAME;} \
array1d_t & NAME() { return m_ ## NAME;} \
const double NAME(const size_t i) const {return m_ ## NAME(i);} \
double NAME(const size_t i) {return m_ ## NAME(i);} \
void set_ ## NAME(const size_t i, const double value) {m_ ##NAME(i) = value;}
private:

#define M_ARRAY2D(NAME) \
public: \
const array2d_t & NAME() const {return m_ ## NAME;} \
array2d_t & NAME() { return m_ ## NAME;} \
const double NAME(const size_t i0, const size_t i1) const {return m_ ## NAME(i0,i1);} \
double NAME(const size_t i0, const size_t i1) {return m_ ## NAME(i0,i1);} \
void set_ ## NAME(const size_t i0, const size_t i1, const double value) {m_ ##NAME(i0,i1) = value;}
private:

#endif
