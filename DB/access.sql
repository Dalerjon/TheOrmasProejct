INSERT INTO "OrmasSchema".accesses(
            access_id, role_id, access_item_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), (SELECT role_id FROM "OrmasSchema".roles WHERE role_name = 'SUPERUSER'), 
			(SELECT access_item_id FROM "OrmasSchema".access_items WHERE access_item_eng = 'ALL'));
