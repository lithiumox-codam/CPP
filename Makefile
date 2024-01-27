.PHONY: all

SUBDIRS := $(wildcard */ex*)

all: $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@

clean:
	@$(foreach dir,$(SUBDIRS),$(MAKE) -C $(dir) clean;)

fclean:
	@$(foreach dir,$(SUBDIRS),$(MAKE) -C $(dir) fclean;)

re: fclean all

bear: fclean
	@bear -- make all

format:
	@$(foreach dir,$(SUBDIRS),$(MAKE) -C $(dir) format;)

.PHONY: all clean fclean re $(SUBDIRS)
