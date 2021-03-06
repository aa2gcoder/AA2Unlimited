#pragma once

#include "gluam.h"

#define ITERATOR_TYPE(container) decltype(container)::iterator
#define ITERATOR_TYPE_P(container) ITERATOR_TYPE(container)*
#define PUSH_ITERATOR(container,nextfunc) \
	lua_pushlightuserdata(_L, &container); \
	lua_pushcclosure(_L, nextfunc<decltype(container)>, 1); \
	ITERATOR_TYPE_P(container) ud = (ITERATOR_TYPE_P(container))lua_newuserdata(_L, sizeof(ITERATOR_TYPE(container))); \
	auto temp = container.begin(); \
	::memcpy(ud, &temp, sizeof(temp)); \
	return 2;

#define LUA_MAPITERATOR(getter, container) \
	LUA_METHOD(getter, { \
		PUSH_ITERATOR(_self->container, map_iterator_next) \
	})

#define LUA_VECTORITERATOR(getter, container) \
	LUA_METHOD(getter, { \
		PUSH_ITERATOR(_self->container, vector_iterator_next) \
	})

template<class C>
int map_iterator_next(lua_State *L) {
	if (lua_isuserdata(L, 1)) {
		C::iterator* it = (C::iterator*)lua_touserdata(L, 1);
		C* container = (C*)lua_touserdata(L, lua_upvalueindex(1));
		if (*it != container->end()) {
			g_Lua.push((*it)->first);
			g_Lua.push((*it)->second);
			(*it)++;
			return 2;
		}
	}
	return 0;
}

template<class C>
int vector_iterator_next(lua_State *L) {
	if (lua_isuserdata(L, 1)) {
		C::iterator* it = (C::iterator*)lua_touserdata(L, 1);
		C* container = (C*)lua_touserdata(L, lua_upvalueindex(1));
		if (*it != container->end()) {
			g_Lua.push(**it);
			(*it)++;
			return 1;
		}
	}
	return 0;
}

#define LUA_ARRAYITERATOR(getter, ary, limit) \
	LUA_METHOD(getter, { \
		lua_pushlightuserdata(_L, (void*)limit); \
		lua_pushcclosure(_L, array_iterator_next<decltype(_self->ary)>, 1); \
		lua_pushlightuserdata(_L, _self->ary); \
		lua_pushnumber(_L, -1); \
		return 3; \
	})

template<class C>
int array_iterator_next(lua_State *L) {
	if (lua_isuserdata(L, 1) && lua_isnumber(L,2)) {
		C it = (C)lua_touserdata(L, 1);
		int index = (int)lua_tonumber(L, 2) + 1;
		int limit = (int)lua_touserdata(L, lua_upvalueindex(1));
		if (index < limit) {
			g_Lua.push(index);
			g_Lua.push(it + index);
			return 2;
		}
	}
	return 0;
}
