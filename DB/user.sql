INSERT INTO "OrmasSchema".users(
            user_id, user_email, user_name, user_surname, user_phone, user_address, 
            role_id, password, activated)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'ormas_admin@gmail.com', 'admin', 'admin', '929991234', '71 Mars St.', 
            (SELECT role_id FROM "OrmasSchema".roles WHERE role_name = 'SUPERUSER'), 'superuser', true);


