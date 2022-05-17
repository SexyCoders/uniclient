/** @jsx jsx */
import { jsx } from 'theme-ui';
import { Container, Grid } from 'theme-ui';
import SectionHeader from 'components/section-header';
import FeatureCard from 'components/feature-card.js';
import Performance from 'assets/feature/performance.svg';
import Partnership from 'assets/feature/partnership.svg';
import Subscription from 'assets/feature/subscription.svg';
import Support from 'assets/feature/support.svg';

const data = [
  {
    id: 1,
    imgSrc: Performance,
    altText: 'Agile Methodology',
    title: 'Agile Methodology',
    text:
      'Using Agile methodology, we are able to deliver the best results for our clients.',
  },
  {
    id: 2,
    imgSrc: Partnership,
    altText: 'Continuous Integration/Continuous Delivery',
    title: 'Continuous Integration/Continuous Delivery',
    text:
      'Using CI/CD techniques, all our modules are built on top of our infrastructure, running tests and updating it as soon as possible.',
  },
  {
    id: 3,
    imgSrc: Subscription,
    altText: 'Partnership deal',
    title: 'Partnership deal',
    text:
      'Work with us and we will provide you with the best support and support services.',
  },
  {
    id: 4,
    imgSrc: Support,
    altText: 'Contact Us',
    title: 'Contact Us',
    text:
      'Is there anything missing? Contact us and we will be happy to help you.',
  },
];

export default function Feature() {
  return (
    <section sx={{ variant: 'section.feature' }}>
      <Container>
        <SectionHeader
          slogan="Cloud-based platform"
          title="An online, completely modular, company management platform, for anyone, anywhere!"
        />

        <Grid sx={styles.grid}>
          {data.map((item) => (
            <FeatureCard
              key={item.id}
              src={item.imgSrc}
              alt={item.altText}
              title={item.title}
              text={item.text}
            />
          ))}
        </Grid>
      </Container>
    </section>
  );
}

const styles = {
  grid: {
    pt: [0, null, null, null, null, null, 2],
    px: [5, 6, 0, null, 7, 8, 7],
    gridGap: [
      '40px 0',
      null,
      '45px 30px',
      null,
      '60px 50px',
      '70px 50px',
      null,
      '80px 90px',
    ],
    gridTemplateColumns: ['repeat(1,1fr)', null, 'repeat(2,1fr)'],
  },
};
