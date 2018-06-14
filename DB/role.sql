INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0001', 'SUPERUSER', 'The main administrator of system');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0002', 'OWNER', 'Owner of company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0003', 'CO-OWNER', 'Co-Owner of company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0004', 'PRODUCT MANAGER', 'Product manager in company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0005', 'QUALITY MANAGER', 'Quality manager in company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0006', 'PURCHASING  MANAGER', 'Purchasing  manager in company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0007', 'PR MANAGER', 'Public relations manager in company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0008', 'SALES MANAGER', 'Sales manager in company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0009', 'HR MANAGER', 'Human resources manager in company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0010', 'CHIEF ACCOUNTANT', 'Chief accountant in company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0011', 'ACCOUNTANT', 'Accountant in company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0012', 'EXPEDITOR', 'Expeditor in company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0013', 'CLIENT', 'Client of company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0014', 'STOCK MANAGER', 'Stock employee');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0015', 'PURVEYOR', 'Purveyor of company');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0016', 'ADMINISTRATORS', 'Admins of ORMAS system');
INSERT INTO "OrmasSchema".roles(
            role_id, role_code, role_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0017', 'ANYKEY', 'This employee do many tasks');






