INSERT INTO "OrmasSchema".product_type(product_type_id, product_type_name, product_type_short_name, product_type_code)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Продукт собственного производста', 'Продукт', 'PRODUCT');
INSERT INTO "OrmasSchema".product_type(product_type_id, product_type_name, product_type_short_name, product_type_code)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Материалы\сырье для производста', 'Сырье', 'RAW');
INSERT INTO "OrmasSchema".product_type(product_type_id, product_type_name, product_type_short_name, product_type_code)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Расходные материалы', 'Расходные', 'CONSUMABLES');