CC = cc
FLAGS = -Wall -Werror -Wextra

# Mandatory Source files: 
CSRC = client.c
SSRC = server.c

# Bonus Source files:
CSRCB = client_bonus.c
SSRCB = server_bonus.c

# ft_printf: 
PRINTF_DIR = ft_printf
PRINF_LIB =$(PRINTF_DIR)/libftprintf.a

# Executables:
CL = client
SRV = server
CLB = client_bonus
SRVB = server_bonus

all : $(CL) $(SRV)

bonus: $(CLB) $(SRVB)

$(PRINF_LIB) : 
	make -C $(PRINTF_DIR)

# Mandatory:
$(CL) : $(CSRC) $(PRINF_LIB)
	$(CC) $(FLAGS) $(CSRC) $(PRINF_LIB) -o $(CL)

$(SRV) : $(SSRC) $(PRINF_LIB)
	$(CC) $(FLAGS) $(SSRC) $(PRINF_LIB) -o $(SRV)

#Bonus:
$(CLB) : $(CSRC) $(PRINF_LIB)
	$(CC) $(FLAGS) $(CSRCB) $(PRINF_LIB) -o $(CLB)

$(SRVB) : $(SSRC) $(PRINF_LIB)
	$(CC) $(FLAGS) $(SSRCB) $(PRINF_LIB) -o $(SRVB)

clean :
	make -C $(PRINTF_DIR) clean

fclean : clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(CL) $(SRV) $(CLB) $(SRVB)

re : fclean all

.PHONY: all clean fclean re
