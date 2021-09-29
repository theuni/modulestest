CXX         = clang++
AR          = ar
ARFLAGS     = -cr
CXXFLAGS    = -O2 -g -Wall -Wextra
LDFLAGS     =

HELLO = helloworld

HELLO_OBJS  =
HELLO_OBJS += helloworld.pcm
HELLO_OBJS += main.o

OBJS  += $(HELLO_OBJS)
PROGS += $(HELLO)

CXXFLAGS_INT = -std=c++2a -stdlib=libc++ -fmodules
CPPFLAGS_INT = -I.
LDFLAGS_INT  =

all: $(PROGS)

V=
_notat_=@
_notat_0=$(_notat_)
_notat_1=@\#
_at_=@
_at_0=$(_at_)
_at_1=
at = $(_at_$(V))
notat = $(_notat_$(V))

DEPDIR=.deps
DEPS = $(addprefix $(DEPDIR)/,$(OBJS:.o=.o.Tpo))
DIRS = $(dir $(DEPS))
DEPDIRSTAMP=$(DEPDIR)/.stamp


-include $(DEPS)

$(DEPDIRSTAMP):
	@mkdir -p $(dir $(DEPS))
	@touch $@

$(OBJS): | $(DEPDIRSTAMP)

$(HELLO): $(HELLO_OBJS)
	$(notat)echo LINK $@
	$(at)$(CXX) $(CXXFLAGS_INT) $(CXXFLAGS) $(LDFLAGS_INT) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(notat)echo CXX $<
	$(at)$(CXX) $(CPPFLAGS_INT) $(CPPFLAGS) $(CXXFLAGS_INT) $(CXXFLAGS) $(CXXFLAGS_EXTRA) -fprebuilt-module-path=. -c -MMD -MP -MF .deps/$@.Tpo $< -o $@

%.pcm: %.cppm
	$(notat)echo CXXP $<
	$(at)$(CXX) $(CPPFLAGS_INT) $(CPPFLAGS) $(CXXFLAGS_INT) $(CXXFLAGS) $(CXXFLAGS_EXTRA) --precompile -c -MMD -MP -MF .deps/$@.Tpo $< -o $@

clean:
	-rm -f $(PROGS)
	-rm -f $(OBJS)
	-rm -f $(DEPS)
	-rm -rf $(DEPDIR)
