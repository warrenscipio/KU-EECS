----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:21:54 04/11/2013 
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
PORT(
	Clk, D : IN STD_LOGIC;
	Q : OUT STD_LOGIC);
	
end toplevel;

architecture Structural of toplevel is

--Component Declaration
COMPONENT gatedDlatch IS
	PORT ( Clk, D : IN STD_LOGIC;
           Q     : OUT STD_LOGIC);
END COMPONENT gatedDlatch;


--Declare Signals
SIGNAL Q_m: STD_LOGIC;

begin
--Component Instanriation

Slave: gatedDlatch
	PORT MAP (
	Clk => NOT Clk,
	D => Q_m,
	Q => Q);
	
	
	
Master: gatedDlatch
	PORT MAP (
	Clk => Clk,
	D => D,
	Q => Q_m);
	
	

end Structural;

