TARGET:=main
SOURCE_FILES:=$(wildcard *.c)
INCLUDE_FILES:=$(wildcard *.h)
INCLUDE_FILES+=$(wildcard *.h)
 
OBJ:=$(patsubst %.c, %.o, $(SOURCE_FILES))
 
C_FLAGS:= -g -Wall -O2 \
          -fsanitize=address
 
LINK_MODULES:=-pthread
 
LDFLAGS := -L../out/lib/
#LINK_MODULES    += -lmodulename
 
$(TARGET):$(OBJ)
	gcc $(C_FLAGS) $(LINK_MODULES) $(LDFLAGS) -o $(TARGET) $(OBJ)
 
%.o:%.c $(INCLUDE_FILES)
	gcc $(C_FLAGS) -c -o $@ $<
 
.PHONY:clean
clean:
	rm -f $(TARGET) $(OBJ)
