----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:58:38 04/25/2013 
-- Design Name: 
-- Module Name:    display_driver3 - Behavioral 
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

entity display_driver3 is

	Port ( inputs : in  STD_LOGIC_VECTOR (3 downto 0);
           seg_out : out  STD_LOGIC_VECTOR (6 downto 0));
			  
end display_driver3;

architecture Behavioral of display_driver3 is

begin


with inputs select
seg_out <=


"1111111" when x"0",
"1111111" when x"1" ,
"1000000" when x"2" ,
"1111001" when x"3" ,
"0100100" when x"4" ,
"0110000" when x"5" ,
"0011001" when x"6" ,
"0010010" when x"7" ,
"0000010" when x"8" ,
"1111000" when x"9" ,
"0000000" when x"A" ,
"0010000" when x"B" ,
"1111111" when others;


end Behavioral;