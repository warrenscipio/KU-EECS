----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:24:41 04/18/2013 
-- Design Name: 
-- Module Name:    clock_divider - Behavioral 
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

entity clock_divider is
	PORT(
		Clk : IN STD_LOGIC;
		message_clk : OUT STD_LOGIC);
		
end clock_divider;

architecture Behavioral of clock_divider is

SIGNAL count : STD_LOGIC_VECTOR(25 downto 0);
begin

process(clk)
begin
   if (clk'event and clk='1') then
   count <= count + 1;
   end if;
	
end process;



message_clk <= count(24);

end Behavioral;

