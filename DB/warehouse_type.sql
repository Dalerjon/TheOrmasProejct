INSERT INTO "OrmasSchema".warehouse_type(
            warehouse_type_id, warehouse_type_code, warehouse_type_purpose, 
            warehouse_type_name)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'RAW', 'Склад сырья', 'Склад сырья');
INSERT INTO "OrmasSchema".warehouse_type(
            warehouse_type_id, warehouse_type_code, warehouse_type_purpose, 
            warehouse_type_name)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'GOODS', 'Товарный склад', 'Товарный склад');
INSERT INTO "OrmasSchema".warehouse_type(
            warehouse_type_id, warehouse_type_code, warehouse_type_purpose, 
            warehouse_type_name)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'PRODUCT', 'Склад готовой продукции', 'Склад готовой продукции');
INSERT INTO "OrmasSchema".warehouse_type(
            warehouse_type_id, warehouse_type_code, warehouse_type_purpose, 
            warehouse_type_name)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'PRODUCTION', 'Производственный склад', 'Производственный склад');