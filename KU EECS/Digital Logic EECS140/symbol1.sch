VERSION 6
BEGIN SCHEMATIC
    BEGIN ATTR DeviceFamilyName "spartan3e"
        DELETE all:0
        EDITNAME all:0
        EDITTRAIT all:0
    END ATTR
    BEGIN NETLIST
        SIGNAL XLXN_2
        SIGNAL XLXN_5
        SIGNAL A
        SIGNAL XLXN_4
        SIGNAL XLXN_16
        SIGNAL C
        SIGNAL XLXN_18
        SIGNAL B
        SIGNAL Y
        SIGNAL XLXN_21
        SIGNAL XLXN_22
        SIGNAL XLXN_24
        SIGNAL XLXN_25
        SIGNAL XLXN_26
        SIGNAL XLXN_27
        SIGNAL XLXN_28
        SIGNAL XLXN_29
        SIGNAL XLXN_30
        SIGNAL XLXN_31
        PORT Input A
        PORT Input C
        PORT Input B
        PORT Output Y
        BEGIN BLOCKDEF and3
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -64 64 -64 
            LINE N 0 -128 64 -128 
            LINE N 0 -192 64 -192 
            LINE N 256 -128 192 -128 
            LINE N 64 -176 144 -176 
            LINE N 144 -80 64 -80 
            ARC N 96 -176 192 -80 144 -80 144 -176 
            LINE N 64 -64 64 -192 
        END BLOCKDEF
        BEGIN BLOCKDEF and2
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -64 64 -64 
            LINE N 0 -128 64 -128 
            LINE N 256 -96 192 -96 
            ARC N 96 -144 192 -48 144 -48 144 -144 
            LINE N 144 -48 64 -48 
            LINE N 64 -144 144 -144 
            LINE N 64 -48 64 -144 
        END BLOCKDEF
        BEGIN BLOCKDEF or3
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -64 48 -64 
            LINE N 0 -128 72 -128 
            LINE N 0 -192 48 -192 
            LINE N 256 -128 192 -128 
            ARC N 28 -256 204 -80 112 -80 192 -128 
            ARC N -40 -184 72 -72 48 -80 48 -176 
            LINE N 48 -64 48 -80 
            LINE N 48 -192 48 -176 
            LINE N 112 -80 48 -80 
            ARC N 28 -176 204 0 192 -128 112 -176 
            LINE N 112 -176 48 -176 
        END BLOCKDEF
        BEGIN BLOCKDEF inv
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -32 64 -32 
            LINE N 224 -32 160 -32 
            LINE N 64 -64 128 -32 
            LINE N 128 -32 64 0 
            LINE N 64 0 64 -64 
            CIRCLE N 128 -48 160 -16 
        END BLOCKDEF
        BEGIN BLOCKDEF title
            TIMESTAMP 2000 1 1 10 10 10
            LINE N -764 -288 -796 -256 
            LINE N -732 -256 -764 -288 
            LINE N -776 -256 -732 -256 
            LINE N -788 -264 -776 -256 
            LINE N -840 -256 -796 -256 
            LINE N -804 -256 -836 -288 
            LINE N -800 -256 -832 -288 
            LINE N -796 -256 -828 -288 
            LINE N -832 -288 -800 -320 
            LINE N -828 -288 -796 -320 
            LINE N -828 -352 -796 -384 
            LINE N -840 -384 -796 -384 
            LINE N -796 -384 -764 -352 
            LINE N -800 -320 -832 -352 
            LINE N -796 -320 -828 -352 
            LINE N -804 -320 -836 -352 
            LINE N -832 -352 -800 -384 
            LINE N -836 -352 -804 -384 
            LINE N -872 -352 -840 -384 
            LINE N -868 -352 -836 -384 
            LINE N -732 -384 -764 -352 
            LINE N -776 -384 -732 -384 
            LINE N -788 -376 -776 -384 
            LINE N -764 -356 -736 -384 
            LINE N -768 -360 -740 -384 
            LINE N -768 -356 -740 -384 
            LINE N -772 -360 -744 -384 
            LINE N -772 -360 -748 -384 
            LINE N -772 -360 -752 -384 
            LINE N -840 -352 -808 -384 
            LINE N -844 -352 -812 -384 
            LINE N -848 -352 -816 -384 
            LINE N -852 -352 -820 -384 
            LINE N -816 -256 -848 -288 
            LINE N -820 -256 -852 -288 
            LINE N -872 -352 -828 -352 
            LINE N -836 -320 -868 -352 
            LINE N -832 -320 -864 -352 
            LINE N -828 -320 -860 -352 
            LINE N -824 -320 -856 -352 
            LINE N -872 -288 -840 -320 
            LINE N -872 -288 -828 -288 
            LINE N -860 -352 -828 -384 
            LINE N -864 -352 -832 -384 
            LINE N -856 -352 -824 -384 
            LINE N -856 -288 -824 -320 
            LINE N -852 -288 -820 -320 
            LINE N -848 -288 -816 -320 
            LINE N -844 -288 -812 -320 
            LINE N -840 -288 -808 -320 
            LINE N -836 -288 -804 -320 
            LINE N -868 -288 -836 -320 
            LINE N -864 -288 -832 -320 
            LINE N -860 -288 -828 -320 
            LINE N -840 -320 -872 -352 
            LINE N -820 -320 -852 -352 
            LINE N -816 -320 -848 -352 
            LINE N -812 -320 -844 -352 
            LINE N -808 -320 -840 -352 
            LINE N -808 -256 -840 -288 
            LINE N -812 -256 -844 -288 
            LINE N -836 -256 -868 -288 
            LINE N -840 -256 -872 -288 
            LINE N -824 -256 -856 -288 
            LINE N -828 -256 -860 -288 
            LINE N -832 -256 -864 -288 
            LINE N -772 -364 -756 -384 
            LINE N -776 -364 -756 -384 
            LINE N -776 -368 -760 -384 
            LINE N -780 -368 -764 -384 
            LINE N -780 -372 -768 -384 
            LINE N -784 -372 -772 -384 
            LINE N -784 -376 -772 -384 
            LINE N -612 -272 -612 -368 
            LINE N -616 -272 -616 -368 
            LINE N -620 -272 -620 -368 
            LINE N -564 -276 -612 -276 
            LINE N -456 -272 -456 -368 
            LINE N -460 -272 -460 -368 
            LINE N -640 -272 -640 -368 
            LINE N -392 -272 -444 -368 
            LINE N -392 -368 -444 -272 
            LINE N -660 -272 -712 -368 
            LINE N -660 -368 -716 -272 
            LINE N -544 -272 -544 -368 
            LINE N -644 -272 -644 -368 
            LINE N -636 -272 -636 -368 
            LINE N -656 -272 -708 -368 
            LINE N -468 -272 -520 -368 
            LINE N -660 -272 -716 -368 
            LINE N -664 -272 -720 -368 
            LINE N -524 -272 -524 -368 
            LINE N -528 -272 -528 -368 
            LINE N -632 -272 -632 -368 
            LINE N -468 -272 -524 -368 
            LINE N -540 -272 -540 -368 
            LINE N -464 -272 -516 -368 
            LINE N -460 -272 -516 -368 
            LINE N -548 -272 -548 -368 
            LINE N -388 -272 -440 -368 
            LINE N -564 -272 -612 -272 
            LINE N -664 -368 -720 -272 
            LINE N -772 -256 -784 -264 
            LINE N -784 -268 -772 -256 
            LINE N -768 -256 -780 -268 
            LINE N -780 -272 -764 -256 
            LINE N -760 -256 -776 -272 
            LINE N -776 -276 -756 -256 
            LINE N -756 -256 -772 -276 
            LINE N -772 -280 -752 -256 
            LINE N -748 -256 -772 -280 
            LINE N -772 -280 -744 -256 
            LINE N -740 -256 -768 -280 
            LINE N -768 -284 -740 -256 
            LINE N -736 -256 -764 -284 
            LINE N -388 -272 -436 -368 
            LINE N -384 -272 -436 -368 
            LINE N -388 -368 -440 -272 
            LINE N -112 -176 -1140 -176 
            BEGIN LINE W -1136 -416 -1136 -212 
            END LINE
            BEGIN LINE W -80 -416 -80 -220 
            END LINE
            BEGIN LINE W -1136 -416 -80 -416 
            END LINE
            LINE N -1136 -128 -80 -128 
            LINE N -1132 -220 -80 -220 
            BEGIN LINE W -80 -80 -352 -80 
            END LINE
            BEGIN LINE W -1136 -80 -352 -80 
            END LINE
            BEGIN LINE W -1136 -224 -1136 -80 
            END LINE
            BEGIN LINE W -144 -80 -152 -80 
            END LINE
            BEGIN LINE W -80 -224 -80 -80 
            END LINE
            LINE N -112 -176 -80 -176 
            LINE N -176 -128 -144 -128 
            LINE N -296 -128 -296 -80 
        END BLOCKDEF
        BEGIN BLOCK XLXI_1 and3
            PIN I0 C
            PIN I1 XLXN_22
            PIN I2 A
            PIN O XLXN_29
        END BLOCK
        BEGIN BLOCK XLXI_2 and2
            PIN I0 XLXN_22
            PIN I1 XLXN_24
            PIN O XLXN_30
        END BLOCK
        BEGIN BLOCK XLXI_3 and2
            PIN I0 XLXN_28
            PIN I1 B
            PIN O XLXN_31
        END BLOCK
        BEGIN BLOCK XLXI_4 or3
            PIN I0 XLXN_31
            PIN I1 XLXN_30
            PIN I2 XLXN_29
            PIN O Y
        END BLOCK
        BEGIN BLOCK XLXI_5 inv
            PIN I XLXN_4
            PIN O XLXN_24
        END BLOCK
        BEGIN BLOCK XLXI_7 inv
            PIN I C
            PIN O XLXN_28
        END BLOCK
        BEGIN BLOCK XLXI_6 inv
            PIN I B
            PIN O XLXN_22
        END BLOCK
        BEGIN BLOCK XLXI_12 title
            ATTR NameFieldText "  Warren Scipio"
            ATTR TitleFieldText "EECS 140 Lab 2 Schematic"
        END BLOCK
    END NETLIST
    BEGIN SHEET 1 3520 2720
        INSTANCE XLXI_1 1728 864 R0
        INSTANCE XLXI_2 1728 1088 R0
        INSTANCE XLXI_3 1728 1312 R0
        INSTANCE XLXI_4 2272 1104 R0
        BEGIN BRANCH A
            WIRE 736 688 1536 688
            WIRE 1536 672 1728 672
            WIRE 1536 672 1536 688
        END BRANCH
        INSTANCE XLXI_5 1008 800 R0
        BEGIN BRANCH XLXN_4
            WIRE 992 672 1008 672
            WIRE 992 672 992 768
            WIRE 992 768 1008 768
        END BRANCH
        INSTANCE XLXI_7 1168 1216 R0
        BEGIN BRANCH C
            WIRE 784 1296 1072 1296
            WIRE 1072 1296 1440 1296
            WIRE 1072 1184 1168 1184
            WIRE 1072 1184 1072 1296
            WIRE 1440 800 1728 800
            WIRE 1440 800 1440 1296
        END BRANCH
        INSTANCE XLXI_6 1200 960 R0
        BEGIN BRANCH B
            WIRE 784 1040 1120 1040
            WIRE 1120 1040 1632 1040
            WIRE 1632 1040 1632 1184
            WIRE 1632 1184 1728 1184
            WIRE 1120 928 1200 928
            WIRE 1120 928 1120 1040
        END BRANCH
        IOMARKER 736 688 A R180 28
        IOMARKER 784 1040 B R180 28
        IOMARKER 784 1296 C R180 28
        BEGIN BRANCH Y
            WIRE 2528 976 2560 976
        END BRANCH
        IOMARKER 2560 976 Y R0 28
        BEGIN BRANCH XLXN_22
            WIRE 1424 928 1568 928
            WIRE 1568 928 1568 1024
            WIRE 1568 1024 1728 1024
            WIRE 1568 736 1568 928
            WIRE 1568 736 1728 736
        END BRANCH
        BEGIN BRANCH XLXN_24
            WIRE 1232 768 1472 768
            WIRE 1472 768 1472 960
            WIRE 1472 960 1728 960
        END BRANCH
        BEGIN BRANCH XLXN_28
            WIRE 1392 1184 1552 1184
            WIRE 1552 1184 1552 1248
            WIRE 1552 1248 1728 1248
        END BRANCH
        BEGIN BRANCH XLXN_29
            WIRE 1984 736 2272 736
            WIRE 2272 736 2272 912
        END BRANCH
        BEGIN BRANCH XLXN_30
            WIRE 1984 992 2128 992
            WIRE 2128 976 2128 992
            WIRE 2128 976 2272 976
        END BRANCH
        BEGIN BRANCH XLXN_31
            WIRE 1984 1216 2272 1216
            WIRE 2272 1040 2272 1216
        END BRANCH
        BEGIN INSTANCE XLXI_12 2592 1776 R0
        END INSTANCE
    END SHEET
END SCHEMATIC
