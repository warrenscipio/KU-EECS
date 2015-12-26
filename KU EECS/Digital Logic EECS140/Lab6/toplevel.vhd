----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:19:43 03/14/2013 
-- Design Name: 
-- Module Name:    toplevel - Behavioral 
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

entity toplevel is

    PORT (
 X : IN STD_LOGIC_VECTOR(5 DOWNTO 0);
 Y : OUT STD_LOGIC);
 
end toplevel;

ARCHITECTURE Behavioral of toplevel IS
BEGIN
Y <= X(5) XOR X(4) XOR X(3) XOR X(2) XOR X(1) XOR X(0);

END ARCHITECTURE Behavioral;