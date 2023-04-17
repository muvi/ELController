module arm() {
    polygon(points=[[0, 0.5], [3.4, 3.2], [6.6, 1.05], [3.0, 1.05], [1.7, 0]]);
}

module jst_sm_plug() {
    translate([0, -2.8, 0]) cube([12, 5.6, 5.1]);
    translate([4.5, 2.8, 0.55]) linear_extrude(3.9) arm();
    translate([4.5, -2.8, 0.55]) mirror([0, 1, 0]) linear_extrude(3.9) arm();
    translate([11.5, -2.0, 1.2]) cube([20.5, 4.0, 1.9]);
    //bottom flap
    translate([10.45, -2.8, -1.3]) cube([1.55, 5.6, 1.3 + 1]);
    //top left flap
    translate([10.45, -2.8, 5.1 - 1]) cube([1.55, 1.55, 1.3 + 1]);
    //top right flap
    translate([10.45, 2.8 - 1.55, 5.1 - 1]) cube([1.55, 1.55, 1.3 + 1]);
}

module jst_sm_socket() {
    translate([12 - 4.8 -20, -(8.25 / 2), -1.3]) cube([20, 8.25, 7.7]);
    translate([12 - 8.45 - 11.25, -(3.3 / 2), 7.7 - 1.3 - 1]) cube([11.25, 3.3, 3.3 + 1]);
}

module jst_sm_combination() {
    translate([1, 0, 0]) {
        jst_sm_plug();
        jst_sm_socket();
    }
}

carrier_width = 16;
carrier_length = 20;
carrier_split_height = 2.5;
carrier_split_margin = 0.12;
registration_hole_radius = 1;
registration_hole_offset = 1.5;
registration_hole_margin = 0.12;
registration_hole_depth = 2;

module registration_hole(positive) {
    radius = registration_hole_radius + (positive ? -registration_hole_margin : registration_hole_margin);
    cylinder(h=10, r1=radius, r2=radius, $fn=50);
}

module plug_carrier_underside() {
    difference() {
        bottom_offset = 3.0;
    
        translate([0, -(carrier_width / 2), 0]) cube([carrier_length, carrier_width, carrier_split_height + carrier_split_margin + bottom_offset]);
        translate([0, 0, bottom_offset]) jst_sm_combination();
    
        //registration holes
        translate([carrier_length - registration_hole_radius - registration_hole_offset, -(carrier_width / 2) + registration_hole_radius + registration_hole_offset, bottom_offset + carrier_split_height - registration_hole_depth]) registration_hole(false);

        translate([carrier_length - registration_hole_radius - registration_hole_offset, (carrier_width / 2) - registration_hole_radius - registration_hole_offset, bottom_offset + carrier_split_height - registration_hole_depth]) registration_hole(false);
    }
}

module plug_carrier_upperside() {
    rotate([180, 0, 0]) {
        difference() {
    
            translate([0, -(carrier_width / 2), 0]) cube([carrier_length, carrier_width, 9]);
            translate([0, 0, -carrier_split_height + carrier_split_margin])    jst_sm_combination();
        }
        //registration holes
        translate([carrier_length - registration_hole_radius - registration_hole_offset, -(carrier_width / 2) + registration_hole_radius + registration_hole_offset, -registration_hole_depth + registration_hole_margin]) registration_hole(true);

        translate([carrier_length - registration_hole_radius - registration_hole_offset, (carrier_width / 2) - registration_hole_radius - registration_hole_offset, -registration_hole_depth + registration_hole_margin]) registration_hole(true);
    }
}

plug_carrier_upperside();