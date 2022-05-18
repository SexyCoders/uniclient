/** @jsx jsx */
import { jsx, Image } from 'theme-ui';
import { Link } from 'components/link';

export default function Logo({ src, ...rest }) {
  return (
     <Link
       path="/"
       sx={{
         variant: 'links.logo',
         display: 'flex',
         cursor: 'pointer',
         mr: 15,
       }}
       {...rest}
     >
       <Image src="https://lib.sexycoders.org/logos/uniclient_r_classic_logo_no_bg.png" alt="startup landing logo" style={{width:"60%"}}/> 
     </Link>
    //<h1>TheBig4</h1>
  );
}
