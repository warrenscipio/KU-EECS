----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:29:30 12/03/2012 
-- Design Name: 
-- Module Name:    4bit_counter - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity counter is
	Port ( clock, Enable, load_n, clear_n: in STD_LOGIC;
			 INITIAL_VALUE: in STD_LOGIC_VECTOR (3 downto 0);
			 counter_output: out STD_LOGIC_VECTOR (3 downto 0));
end counter;

architecture Behavioral of counter is
signal counter_signal:std_logic_vector(3 downto 0) :="0000";
begin
process (clock, clear_n)
begin
   if clear_n='0' then
     counter_signal <= (others=>'0');
   elsif (clock'event and clock='1') then
     if load_n = '0' then
     counter_signal <=initial_value;
     else
     if enable ='1' then
     counter_signal <= counter_signal +1;
     else
     counter_signal <= counter_signal;
     end if;
   end if;
   end if;
end process;
counter_output <= counter_signal;
end Behavioral;

